from math import sqrt

ans = []

def yes(t):
    global n,ans
    for k in range(2,11):
        flag = False
        m = 0
        for i in range(n-1,-1,-1):
            m = m*k + ((t>>i)&1)
        r = min(int(sqrt(m)+1)+1,1008)
        for i in range(2,r):
            if m%i == 0:
                ans.append(i)
                flag = True
                break
        if not flag: 
            return False
    return True

def main():
    f = open('test.txt','r')
    w = open('ansC.txt','w')
    T = int(f.readline())
    global n,ans
    n,j = map(int,f.readline().split())
    w.write('Case #1:\n');
    #print 'Case #1:'
    for i in range(1<<(n-2)):
        t = (i<<1) + 1 + (1<<(n-1))
        if yes(t):
            j -= 1
            s = ''
            for k in range(n-1,-1,-1):
                s += str((t>>k)&1)
            for c in ans:
                s += ' ' + str(c)
            #print s
            w.write(s+'\n')
        ans = []
        if not j: break

main()
