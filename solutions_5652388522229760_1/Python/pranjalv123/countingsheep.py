def sheep(n):
    digits = set()
    i = 1
    x = 0
    maxi = 10**len(str(x))
    if n == 0:
        return "INSOMNIA"
    while len(digits) < 10:
        x += n
        digits.update(str(x))

        if len(digits) == 10:
            return x
        i += 1
    return "INSOMNIA"


t = int(raw_input())  # read a line with a single integer

for i in xrange(1, t + 1):
  n = int(raw_input())
  print "Case #{}: {}".format(i, sheep(n))
