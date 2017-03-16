
if __name__=='__main__':
    T = int(input())
    
    for i in range(1,T+1):
        ans = 'Case #'+str(i)+': '
        inp = input().split(' ')
        [C,F,X] = [float(a) for a in inp]
        cr = 2.0
        bT = 0
        best = X / cr
        while True:
            bT += C/cr
            cr += F
            fT = X / cr
            cand = bT + fT
##            print('\tTesting '+str(cand))
            if cand > best:
                break
            else:
                best = cand
        print(ans,end='')
        print("%.7f" % best)
