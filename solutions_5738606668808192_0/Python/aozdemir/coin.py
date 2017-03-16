

def is_prime(n):
    if n == 2 or n == 3: return 0
    if n < 2: return 0
    if n%2 == 0: return 2
    if n < 9: return 0
    if n%3 == 0: return 3
    r = int(n**0.5)
    f = 5
    while f <= r:
        if n%f == 0: return f
        if n%(f+2) == 0: return f+2
        f +=6
    return 0

N = 16
J = 50
for i in range(0,2**(N-2)):
    if J == 0:
        break
    s = "1"+ ("{0:014b}".format(i)) + "1"
    nope = False
    l = []
    for b in range(2, 11):
        N = int(s, b)
        f = is_prime(N)
        if (f > 0):
            l.append(f)
        else:
            nope = True
            break
    if not nope:
        J -= 1
        print(s + " " + " ".join(map(str, l)))

