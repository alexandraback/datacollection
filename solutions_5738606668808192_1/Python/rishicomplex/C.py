
import random

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997]


def convBase(s, base):
    ret = 0
    #print s,
    while len(s) != 0:
        ret *= base
        if s[0] == "1":
            ret += 1
        s = s[1:]
    #print "converts to " + str(ret)  + " in base " + str(base)
    return ret

def getDiv(no):
    for prime in primes:
        if no % prime == 0:
            return prime
    return -1
        

def genJam(N):
    ret = "1"
    for i in range(N - 2):
        r = random.randint(0, 1)
        if r == 0:
            ret += "0"
        else:
            ret += "1"
    ret += "1"
    return ret
        


def main():
    T = raw_input()
    N, J = map(int, raw_input().split(' '))
    #print N, J, N + J
    count = 0
    ans = []
    while count != J :
        s = genJam(N)
        temp_ans = []
        flag = 0
        for base in range(2, 11):
            no = convBase(s, base)
            div = getDiv(no)
            if div == -1:
                flag = 1
                break
            temp_ans.append(div)
        if flag == 0:
            count += 1
            ans.append((s, temp_ans))
    print "Case #1:"
    for proof in ans:
        print proof[0],
        for divisor in proof[1]:
            print divisor,
        print
            
                
        
    

main()
