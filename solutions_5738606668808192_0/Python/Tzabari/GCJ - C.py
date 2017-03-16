Primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]


def GetDivisors(s):
    global Primes
    nums = [int(s,i) for i in range(2,11)]
    s= ''
    for i in range(0,len(nums)):
        div = None
        for p in Primes:
            if nums[i]%p == 0:
                div = p
                break
        if div is None:
            return None
        s = s + ' ' + str(div)
    return s

file = 'C-small-attempt0.in'
readf = open(file, 'r')
T = int(readf.readline())
writef = open('Output', 'w')
line = readf.readline()
line = line.split()
N = int(line[0])
J = int(line[1])
for i in range(1,T+1):
    j=0
    count = 0
    writef.write('Case #'+str(i)+': \n')
    while j<J:
        num = 2*count + 1 + 2**(N-1)
        s = GetDivisors("{0:b}".format(num))
        if s is not None:
            j +=1
            writef.write("{0:b}".format(num) + s + ' \n')
        count += 1
writef.close()

