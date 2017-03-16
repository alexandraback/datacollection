def simple(s):
    for i in xrange(2,11):
        num = int(s,i)
        if not (num%2 == 0 or num%3 == 0 or num%5 == 0 or num%7 == 0):
            return False
    return True

def get_line(s):
    line = s+" "
    for i in xrange(2,11):
        num = int(s,i)
        prime = [2,3,5,7]
        current = 3
        for i in prime:
            if num%i==0:
                current = i
        line+=str(current)+" "
    return line[:-1]+"\n"

def for_6(s):
    num = int(s,6)
    return num%3 == 0 or num%5 == 0 or num%7 == 0

def f(N,J):
    remaining = J
    out = ""
    midN = N-2
    for i in xrange(2**midN):
        mid = "{0:b}".format(i)
        if len(mid)!=midN:
            mid = "0"*(midN - len(mid)) + mid
        midOnes = mid.count('1')
        totalOnes = midOnes+2
        num = '1'+mid+'1'
        if int(num,2) %3 == 0:
            #print num, totalOnes%2, totalOnes%3,for_6(num)
            if totalOnes % 3 == 0 and totalOnes % 2 == 0 and for_6(num):
                if simple(num):
                    out+=get_line(num)
                    remaining -=1
                    if remaining ==0:
                        return out
    return out
    
#print for_6("1010101")
lines = open("coinin.txt").read().splitlines()
out = ""
for i in xrange(1, len(lines)):
    N = int(lines[i].split()[0])
    J = int(lines[i].split()[1])
    out+="Case #"+str(i)+":\n"+str(f(N,J))
open("coinout.txt","w").write(out)
