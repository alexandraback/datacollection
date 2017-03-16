'''
Created on 2012-4-28

@author: mzh.li
'''

if __name__ == '__main__':
    
    with open("B-small-attempt1.in", 'r') as fi, open("B-small-attempt1.out", "w") as fo:
        T = int(fi.readline())
        for t in range(0,T):
            N = int(fi.readline())
            l1 = [0] * (N + 1)
            l2 = [0] * (N + 1)
            for i in range(1, N+1):
                (l1[i],l2[i]) = tuple([int(j) for j in fi.readline().split()])
            
            fin = 0
            stars = 0
            steps = 0
            fn2 = [0] * (N + 1)
            fn1 = [0] * (N + 1)
            cd = 0
            while fin != N:
                cd = 0
                for i in range(1, N +1):
                    if fn2[i] != 1 and fn1[i] != 1 and stars >= l2[i]:
                        stars += 2
                        fn2[i] = 1
                        fn1[i] = 1
                        fin += 1
                        cd = 1
                        break
                    
                if 0 == cd:
                    for i in range(1, N +1):
                        if fn2[i] != 1 and fn1[i] == 1 and stars >= l2[i]:
                            stars += 1
                            fn2[i] = 1
                            fin += 1
                            cd = 1
                            break
                    
                if 0 == cd:
                    for i in range(1, N +1):
                        if fn1[i] != 1 and stars >= l1[i]:
                            stars += 1
                            fn1[i] = 1
                            cd = 1
                            break
                
                if cd == 0:
                    fo.write("Case #%d: %s\n"%(t + 1, "Too Bad"))
                    break
                else:
                    steps += 1;
            if fin == N:
                fo.write("Case #%d: %d\n"%(t + 1, steps))