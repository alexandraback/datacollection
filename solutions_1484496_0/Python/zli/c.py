#import pickle

def hibit(num):
    hb=0
    while num:
        num=num>>1
        hb+=1
    return hb

needed=hibit(10**5+1)
#needed=hibit(10**12+1)#9+12

def greycodebits(num):
    bits=[0]*(num)
    for i in xrange(num-2):
        bits[i]=hibit(i^(i+1))-1
    return bits

#uncomment to generate
gcb=greycodebits(2**needed)
#pickle.dump(gcb,open("gcb21","w"))

#gcb=pickle.load(open("gcb21"))

#nonexist
for case in range(input()):
    print "Case #"+str(case+1)+":"
    numbers=map(int,raw_input().split())[1:]
    numbers.sort()
    numbers=numbers[:needed]
    sol={} #[None]*(2**needed)
    total=0
    curset=[False]*needed
    for bit in gcb:
    #for i,bit in enumerate(gcb):
        #print i,"".join(map(str,map(int,curset)))

        curset[bit]=not curset[bit]
        if curset[bit]:
            total+=numbers[bit]
        else:
            total-=numbers[bit]
        if total in sol:
            #print curset
            s1=set(numbers[i] for i,val in enumerate(sol[total]) if val)
            s2=set(numbers[i] for i,val in enumerate(curset) if val)
            #print len(sol)
            #print s1
            #print s2
            print " ".join(map(str,s1-s2))
            print " ".join(map(str,s2-s1))
            break
        else:
            sol[total]=curset[:]
