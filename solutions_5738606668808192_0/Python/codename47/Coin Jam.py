Divisors = " 3 4 5 6 7 8 9 10 11"
print("Case #1:")
s = "1000000000000001"
print(s + Divisors)
def acceptable(n):
    accept = []
    k = s[:]
    temp1 = list(k)
    temp1[n] = "1"
    base = "".join(temp1)
    a = n+1
    while a<15:
        k1 = base[:]
        temp2 = list(k1)
        temp2[a] = "1"
        print("".join(temp2) + Divisors)
        a += 2
for i in range(1,14):
    acceptable(i)
