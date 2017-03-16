import array


from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31] # etc.

def probably_prime(n, k):
    """Return True if n passes k rounds of the Miller-Rabin primality
    test (and is probably prime). Return False if n is proved to be
    composite.
    https://stackoverflow.com/questions/14613304/rabin-miller-strong-pseudoprime-test-implementation-wont-work
    """
    if n < 2: return False
    for p in small_primes:
        if n < p * p: return True
        if n % p == 0: return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

class primegen:
        def __init__(self,x):
                self.length = 0
                self.data = array.array('b',[])
                self.generate_primes(x)

        def generate_primes(self,x):
                self.length = ((x)/16) + 1
                self.data = [0] * int(self.length)
                self.max = x
                for i in range(3,x+2,2):
                        j = 2
                        if (self.is_prime(i)):
                                while (j*i) < self.max:
                                        self.set_value(j*i)
                                        j = j + 1

        def get_offset(self,x):
                x = x - 3
                return [int(x/16),int(x%16/2)]

        def is_prime(self,x):
                if (x == 1):
                        return  False
                elif (x % 2) == 0:
                        return False
                else:
                        return self.get_value(x)

        def get_value(self,x):
                t = self.get_offset(x)
                return (self.data[t[0]] & (1 << t[1])) == 0

        def set_value(self,x):
                if (x % 2) == 0:
                        return
                if (x < self.max):
                        t = self.get_offset(x)
                self.data[t[0]] |= (1 << t[1])

        def prime_list(self,x):
                b = [2]
                for i in range(3,x):
                        if (self.is_prime(i)):
                                b.append(i)
                return b



p = primegen(1000)




def output_res(caseno,output, f):
    s = "Case #{}: {}".format(caseno,output)
    print(s)
    f.write(s + "\n")


def solve(N):
    global p
    t = "1" + ((N[0]-2) * "0") + "1"
    v = int(t,2)
    c = 0
    ss = []
    while (c < N[1]):
        s = ["{:b}".format(v)]
        for i in range(2,11):
            j = int("{:b}".format(v),i)

            if (probably_prime(j,100)) != False:
                break
            for x in p.prime_list(1000):
                if (j % x) == 0:
                    s.append(x)
                    break
            else:
                break
        else:
            c += 1
            ss.append((s))
        v += 2

    st = "\n"
    for x in ss:
        st += " ".join(map(str,x))
        st += "\n"
    return st





f = open("input.txt")
#f = open("C-large-practice.in")

outfile = open("output","w+")
T = int(f.readline())
for case in range(1, T + 1):
    N = [int(x) for x in f.readline().split()]
    output_res(case, solve(N),outfile)

