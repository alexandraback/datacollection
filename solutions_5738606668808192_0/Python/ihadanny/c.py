import sys

J=50
N=16

f = open("primes.txt","r")
primes = map(int, f.readline().split())

big_arr = []    
width = N - 2
for i in range(2**width):
    s = "1" + format(i, 'b').zfill(width) + "1"    
    big_arr.append({"n":s, "b": [int(s,base) for base in range(2, 11)], 
                                        "d": [-1]*9, "nd": 0})
#    print big_arr[-1]                                    

print "Case #1:"
found = 0    
for p in primes:
    for l in big_arr:
        if l["nd"] < 9:
            for i, b in enumerate(l["b"]):
                if l["d"][i] == -1 and b % p == 0:
                    l["d"][i] = p
                    l["nd"] += 1
            if l["nd"] == 9:
                print l["n"], " ".join(map(str, l["d"]))
                found +=1
                if found >= J:
                    exit(1)


