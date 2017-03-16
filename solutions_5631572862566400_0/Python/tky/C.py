# Google code jam
import numpy as np



# read number of cases from stdin    
T = int(input()) 

for j in range(1,T+1):

    N = int(input()) # class size

    # read BFF ids (shift down by one for indexing 0..N-1)
    BFF = np.fromstring(input(), dtype=int, sep=' ') - 1

    ids = np.arange(N,dtype=int) # all ids
    subset = np.array([ids[0]]) 
    subsize = np.array([0])

    # start with first child in class
    thisid = 0
    ids = np.delete(ids,0)
    while True:
        thisid = BFF[thisid]
        #print(ids, subset, thisid, BFF[thisid])
        if thisid in set(subset):
            # cannot seat BFF to the right (and make circle larger),
            # since BFF is already seated, next subset determine
            # largest circle

            # find position of last child's BBF in subset to form closed circle
            pos = np.where(subset==thisid)[0][0]
            # does the last child have its BFF sitting left of it
            if pos == (subset.size - 2):
                subsize = np.append(subsize,subset.size)
            else:
                subsize = np.append(subsize,subset.size - pos)
            
            # restart with next child (unless there are less than two left)
            if ids.size < 2:
                break
            else:
                thisid = ids[0]
                subset = np.array([ids[0]])
                ids = np.delete(ids,0)
            
        else:
            # exit if no ids remain
            if ids.size == 0:
                break

            # can seat BFF to the right: add to subset
            # remove id from remaining ids
            #   print("add {}".format(thisid))
            subset = np.append(subset,thisid)
            if thisid in set(ids):
                pos = np.where(ids==thisid)[0][0]
                ids = np.delete(ids,pos)
                                    

    maxsize = np.amax(subsize)
    print("Case #{}: {}".format(j,maxsize))
