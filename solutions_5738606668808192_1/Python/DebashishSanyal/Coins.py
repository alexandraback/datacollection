from math import sqrt
######################################################################
######################################################################
#Make a list of prime numbers upto 65536
#If any number X from (3,2^32) is divisible by any number in this list, X is not a prime.
primes = []
def check_prime1(num):
   if num > 1:
       for i in range(2,int(sqrt(num)+1)):
           if (num % i) == 0:
               return i
       else:
           return -1

for i in range(1,65537):
    if check_prime1(i) == -1:
        primes.append(i)


######################################################################
######################## HELPER FUNCTIONS ############################
######################## HELPER FUNCTIONS ############################
######################################################################

#######
#Using the generated list of primes upto 65536, check if the given number is a prime
#######
def check_prime(num):
   if num > 1:
       for i in primes:
           if i > int(sqrt(num)):
               return -1
           if (num % i) == 0:
               return i
       else:
           return -1


#######
#Converts integer to bits of specific length
######
def makeKbit(c,length):
    d = ("{0:b}".format(c))
    a = length - len(d)
    ad = ""
    while a > 0:
        ad = ad + "0"
        a = a - 1
    result = ad+d
    return result


#######
#Increments given sequence of bits by 1 bit
#######
def increment_bit(bits,N):
    mid = bits[1:-1]
    new_mid = makeKbit((int(mid, 2) + 1),N-2)
    mid = new_mid
    bits = "1" + mid + "1"
    return bits


#######
#Finds the factors for the given bits in all bases from 2 to 10
#returns -1 there's a prime for any base.
#######
def fd(bits):
    result = []
    #print bits
    for base in range(2,11):
        #print base
        a =  int(bits, base)
        r = check_prime(a) #r will be divisor of this base, or -1 if prime
        if r == -1:
            return [-1]
        else:
            result.append(r)
    return result


############## MAIN PROGRAM STARTS #############
############## MAIN PROGRAM STARTS #############
############## MAIN PROGRAM STARTS #############
############## MAIN PROGRAM STARTS #############

result = ""
t = int(raw_input())
for i in range(1, t + 1):
    N, J = [int(s) for s in raw_input().split(" ")]
    mid = (N-2)*"0"
    bits = "1" + mid + "1"
    result_N1 = {}
    while len(result_N1) < J:
        k = fd(bits)
        if k[0] != -1:
            result_N1[bits] = fd(bits)
        bits = increment_bit(bits,N)

    result1 = "Case #{}:\n".format(i)
    for key in result_N1:
        factors = ""
        for factor in result_N1[key]:
            factors = factors + " " + str(factor)
        result1 = result1 + "{}{}\n".format(key, factors)
    result = result + result1


print result
file_name = "output.txt"
text_file = open(file_name, "w")
text_file.write(result)

#for i in xrange(50)
