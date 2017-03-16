def get_digit(n, k):
    return (n // (10**k)) % 10

def set_digit(n, k, d):
    return n + (d - get_digit(n,k)) * 10**k

def make_numbers(c_int, j_int, c_blanks, j_blanks, k, b):
    #fills in the blanks of c_int and j_int with k
    for i in range(b):
        if (i < len(c_blanks)):
            c_int = set_digit(c_int, c_blanks[i], get_digit(k, b-i-1))
        else:
            j_int = set_digit(j_int, j_blanks[i - len(c_blanks)],
                get_digit(k, b-i-1))
    return (c_int, j_int)

def get_leading_zeroes(i, n):
    #returns i as a string so that it has n digits total
    i = str(i)
    zeroes = "0" * (n-len(i))
    return zeroes + i

def run_test():
    c, j = raw_input().split(" ")
    n = len(c)
    min_dist = 10**n
    #find the indices where c and j are blank, and fill in c and j with zeroes
    c_blanks = list()
    j_blanks = list()
    for i in range(n):
        if (c[i] == "?"):
            c_blanks.append(n-i-1)
            c = c[:i] + "0" + c[i+1:]
        if (j[i] == "?"):
            j_blanks.append(n-i-1)
            j = j[:i] + "0" + j[i+1:]
    # print(c_blanks, j_blanks)
    b = len(c_blanks) + len(j_blanks)
    c_int, j_int = int(c), int(j)
    c_best, j_best = None, None

    for i in range(10**b):
        (c_int, j_int) = make_numbers(c_int, j_int, c_blanks, j_blanks, i, b)
        # if (i == 5): print(c_int, j_int)
        d = abs(c_int - j_int)
        if (d < min_dist):
            min_dist = d
            c_best, j_best = c_int, j_int
    return get_leading_zeroes(c_best, n) + " " + get_leading_zeroes(j_best, n)
        

t = int(raw_input())
for i in range(1, t+1):
    print("Case #%d: %s" % (i, run_test()))