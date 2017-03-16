# We construct a family of jamcoins that are divisible by (3, 2, 5, 2, 7, 2, 3, 2, 11)
# 
# 2^n = 8^n = +/- 1 (mod 3) and 4^n = +/- 1 (mod 5)
# and 6^n = +/- 1 (mod 7) and 10^n = +/- 1 (mod 11)
# => same no. of ones on even and odd powers
#
# 3^n, 5^n, 7^n = 1 (mod 2) => Even no. of 1s
#
# Therefore, of the remaining 1s that we can select, it is sufficient to select
# the same number of ones on even and odd powers to form a valid jamcoin with
# the given divisors. (n is known to be even, this is important)

f = open("C-small-attempt0.in", "r")
g = open("C-small.out", "w")

f.readline()
a = f.readline().strip().split()
n_each = (int(a[0]) - 2)/2 # n is known to be even
j = int(a[1])

g.write("Case #1:\n")

count = 0
divisors = (3, 2, 5, 2, 7, 2, 3, 2, 11)
zipped = zip(xrange(2, 11), divisors)

def lpad(a):
    l = len(a)
    if l < n_each:
        return "0" * (n_each - l) + a
    else:
        return a

def test(num):
    for i, div in zipped:
        integral = int(num, i)
        if integral % div != 0: return False

    return True

# Even with this lousy generation there are more than enough numbers
done = False
for d in xrange(2 ** n_each):
    if count >= j:
        done = True
        break
    
    dbin = lpad(bin(d)[2:])

    a = "1"
    for digit in dbin:
        a += digit * 2
    a += "1"

    # Just in case
    if not test(a):
        print a
        break

    g.write(a + " %d %d %d %d %d %d %d %d %d\n" % divisors)

    count += 1
