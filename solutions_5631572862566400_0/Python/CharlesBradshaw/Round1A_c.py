fin= open("C-small-attempt3.in",'r')

fout=open("round1A_C.out",'w')
T = int(fin.readline())

for t in range(T):
    print 'TEst', t
    N= int(fin.readline())
    A = [int(i) for i in fin.readline().split()]
    print N,A
    case = [-1]*N
    length = [-1]*N
    join = [-1]*N
    longestCycle = 0;
    for k  in range(N):
           seen = [0]*N
           count=1;
           bff =k+1
           if A[bff-1] == k+1:
               print 'HEY',k,A
           while not seen[bff-1]:
                seen[bff-1]=count;
                count+=1
                bff = A[bff-1]
           if bff-1==k:
                if count==3:
                    #case3
                   case[k]=3
                else:
                    
                   #case1
                    case[k]=1
                    length[k] = count-seen[bff-1]
                    longestCycle=max(longestCycle,length[k])
           else:
               if count-seen[bff-1]==2:
                   #case2
                   case[k]=2
                   length[k]=count-2
                   join[k]=bff-1
               else:
                   #case4
                    case[k]=4
                    length[k] = count-seen[bff-1]
                    longestCycle=max(longestCycle,length[k])
           #print "kid:" +str(k+1) +" Case "+str(case[k])+" "+str(length[k]) + " "+str(join[k])
    sunof2cycles = 0
    for k in range(N):
        if case[k]==3:
            #print k+1 ,'is an end with'
            maxi = 1
            for l in range(N):
                if join[l]==k:
                    #print "   ",length[l],"as an option"
                    maxi =max(maxi,length[l])
            #print " went with ", maxi
            sunof2cycles+=maxi
    output = max(sunof2cycles,longestCycle)
    print sunof2cycles,longestCycle
    print '\n'
    if max(sunof2cycles,longestCycle)>N:
        print 'Hey'
    fout.write("Case #"+str(t+1)+': ' + str(output) +'\n')
  

fout.close()
fin.close()
