#!/usr/local/bin/python




def main():
    
    import sys
    T = int(sys.stdin.readline())

    i = 1

    for attempt in range(T):
        N = int(sys.stdin.readline())        
        hancho = []
        for pap in range(2*N-1):
            slp = (sys.stdin.readline())
            slp=slp.strip()
            slp = slp.split(' ')
            hancho.append(slp)


        mojo(hancho,N,i)
        i+=1


def mojo(slps,N, poo):
    a = []
    fl = []
    for r in range(2*N-1):
        for c in range(N):
            a.append(slps[r][c])


    digit = []
    for i in range(1,2501):
        digit.append(0)

    for i in range(len(a)):
        digit[int(a[i])-1]+=1

    ans = []
    for i in range(len(digit)):
        if digit[i]%2 != 0:
            ans.append(i+1)


    print "Case #"+str(poo)+":",
    for i in ans:
        print i,
    print ""




    


    


if __name__ == "__main__":
    main()
