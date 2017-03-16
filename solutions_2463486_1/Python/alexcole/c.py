import math

fin = open('/Users/alex/Desktop/codejam/c/C-small-attempt0.in', 'r')
fout = open('/Users/alex/Desktop/codejam/c/C-small-attempt0.out', 'w')

n =fin.readline().strip()
n = int(n)
def genPalidromes(digits):
    if digits==1:
        return range(10)
    if digits%2==0:
        answer = []
        d = digits/2
        for i in range(int(10**(d-1)), 10**d):
            if len(str(i))==d:
                cand = str(i)+str(i)[::-1]
                cand = int(cand)
                if len(str(cand))==digits:
                    answer.append(cand)
        return answer
    else:
        answer = []
        d = digits/2
        for i in range(int(10**(d-1)), 10**d):
            if len(str(i))==d:
                for j in range(10):
                    cand = str(i)+str(j)+str(i)[::-1]
                    cand = int(cand)
                    if len(str(cand))==digits:
                        answer.append(cand)
        return answer


for i in range(n):
    data = fin.readline().strip()
    a, b = data.split(' ')
    a, b = int(a), int(b)
    count = 0
    l1 = len(str(int(math.sqrt(a))))
    l2 = len(str(int(math.sqrt(b))))
    for l in range(l1, l2+1):
        options = genPalidromes(l)
        for opt in options:
            s = opt**2
            if s>=a and s<=b and isPalindrome(s):
                count+=1
    print count
    fout.write("Case #"+str(i+1)+": "+str(count)+"\n")

def isPalindrome(k):
    k=str(k)
    l = len(k)
    for i in range(l/2):
        if k[i]!=k[l-i-1]:
            return False
    return True


    

fin.close()
fout.close()
