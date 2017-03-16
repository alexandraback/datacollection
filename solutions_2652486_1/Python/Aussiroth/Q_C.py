import math

def findfactors(number, maximum):
    factors = []
    i=maximum
    while i>=2:
        if number%i==0:
            factors.append(i)
            number = number/i
        else:
            i-=1
    return factors

infile = open("C-small.txt", "r")
outfile = open("C-out.txt", "w")
outfile.write("Case #1:\n")
testcase = int(infile.readline())
for derp in range(1, testcase+1):
    r, n, m, k = infile.readline().split()
    r,n,m,k = int(r),int(n),int(m),int(k)
    for i in range(0, r):
        numbers = infile.readline().split()
        numbers = [int(i) for i in numbers]
        factors = {}
        for item in numbers:
            currfactors = findfactors(item, m)
            occurrence = {x:currfactors.count(x) for x in currfactors}
            for num in occurrence:
                if num not in factors:
                    factors[num] = occurrence[num]
                else:
                    if occurrence[num]>factors[num]:
                        factors[num]=occurrence[num]
        currn = 0
        output = ''
        temp = 100
        for item in factors:
            if item<temp:
                temp = item
            if currn+factors[item]<n:
                output += factors[item]*str(item)
            else:
                output += (n-currn)*str(item)
            currn += factors[item]
        if len(output)<n:
            if temp:
                output += (n-len(output))*str(temp)
            else:
                output += n-len(output)*'2'
        output += '\n'
        outfile.write(output)
        

infile.close()
outfile.close()
