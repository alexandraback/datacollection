import math

fin = open('/Users/alex/Desktop/codejam/c/C-small-attempt0.in', 'r')
fout = open('/Users/alex/Desktop/codejam/c/C-small-attempt0.out', 'w')

n =fin.readline().strip()
n = int(n)

for i in range(n):
    data = fin.readline().strip()
    a, b = data.split(' ')
    a, b = int(a), int(b)
    count = 0
    for j in range(int(math.sqrt(a)-1), int(math.sqrt(b))+1):
        if isPalindrome(j) and isPalindrome(j**2) and j**2>=a and j**2<=b:
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
