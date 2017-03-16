from math import sqrt

def outpcoin(b):
    file=open("output.txt","a")
    s=""
    for i in b:
        s= s + str(i) +" "
    s = s[:-1] + "\n"
    file.write(s)
    file.close
    print(s)

def gotnofactors(vari,primes):
    #reads an integer and sees if it is prime. If not, returns smallest prime factor found
    if vari<2:
        return False
    n=0
    until = sqrt(vari)//1 +1
    while n<len(primes):
        if primes[n]>until:
            return "y"
        if vari%primes[n]==0:
            return primes[n]
        n+=1
    return "y"

def primelist(no = 300):
    primes = []
    current = 1
    while len(primes) < no:
        current+=1
        if gotnofactors(current,primes)=="y":
            primes.append(current)
    return primes

def testcoin(coin):
    global coinlength
    global primes
    n = 2
    outputThis = []
    while n <11:
        value = 1
        value+= n**(coinlength - 1)
        for i , digit in enumerate(coin):
            value += int(digit) * (n**(i+1))
        sfactor = gotnofactors(value , primes)
        if sfactor=="y":
            return False
        outputThis.append(sfactor)
        n+=1
    coin = coin[::-1]
    exactcoin = "1" + ''.join(coin) + "1"
    outputThis.insert(0, exactcoin)
    outpcoin(outputThis)
    return True

q=open ("output.txt","w")
q.write("Case #1:\n")
q.close()

# change source here!!

inp = open("C-small-attempt0.in","r")

# End

a= []
for line in inp:
    if "\n" in line:
        a.append(line[0:-1])
    else:
        a.append(line)
inp.close()
info = a[1]
info = info.split(" ")
coin = []
coinlength = int(info[0])
for i in range(coinlength-2):
    coin.append("0")
coinsneeded = int(info[1])
nocoins = 0
primes = primelist()
while nocoins < coinsneeded:
    if testcoin(coin):
        nocoins+=1
    for i,digit in enumerate(coin):
        coin.pop(i)
        if digit == "0":
            coin.insert(i, "1")
            break
        coin.insert(i, "0")
        
        
