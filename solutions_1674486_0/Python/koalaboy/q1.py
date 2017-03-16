import sys
from collections import deque

def find_end(c, inh_rel):
    start_list = deque([c])
    result = deque([])
    while len(start_list) != 0: 
        x = start_list.popleft() 
        if inh_rel[x]== []:
            result.append(x)
        else:
            start_list.extend( inh_rel[x] )
        #print 'start_list', start_list
        #print 'result', result
        #raw_input()
    return result

if __name__ == '__main__':
    f = open(sys.argv[1])
    cases = int( f.readline().strip() )
    for n in xrange(1, cases + 1):
        result = 'No'
        classes = int( f.readline().strip() )
        inh_rel = [ [] ]
        for i in xrange(classes):
            l = [int(j) for j in f.readline().strip().split() ]
            l.pop(0) 
            inh_rel.append(l)
        
        #print inh_rel
        #raw_input()
        for i in xrange(1, classes + 1):
            if inh_rel[i] != []:
                #print 'i',i
                end_list = find_end(i, inh_rel)
                #print 'end_list', end_list
                #raw_input()
                if  i in end_list or len(end_list) != len(set(end_list)): 
                    result = 'Yes'
                    break
                    
        print 'Case #%d: %s'%(n ,result)
