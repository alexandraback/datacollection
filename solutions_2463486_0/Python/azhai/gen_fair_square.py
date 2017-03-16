N = 100000

def is_pal(x):
    return str(x) == str(x)[::-1]

def make_pal1(x):
    return int(str(x) + str(x)[::-1])

def make_pal2(x):
    return int(str(x)[:-1] + str(x)[::-1])

for i in xrange(1, N):
    x = make_pal1(i)
    if is_pal(x * x):
        print x * x

    x = make_pal2(i)
    if is_pal(x * x):
        print x * x
