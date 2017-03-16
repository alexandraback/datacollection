import os, sys

def main():
    f = open("in")

    line = f.readline()
    T = int(line)

    for case in range(T):
        line = f.readline().split()
        A = int(line[0])
        B = int(line[1])
        
        probs = f.readline().split()

        ans = B + 2 # Enter. B chars. Enter.

        prob = 1.0
        for i in range(A+1):                   # 12345  A=5 i=2
            #Delete characters i and beyond        xxx
            if i>0:
                prob *= float(probs[i-1]) # probability of success
            #  num deleted, typed, enter
            exp = (A-i) + (B-i) + 1 + (1-prob) * (B + 1)
            ans = min(exp, ans)
        
        print "Case #%d: %f" % (case+1, ans)
    

if __name__ == '__main__':
    main()
