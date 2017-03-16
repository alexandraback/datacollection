if __name__ == "__main__":
    t = raw_input()
    nj = raw_input()
    n, j = tuple(int(x) for x in nj.split(" "))
    print "Case #1:"
    facts = [str(x**(n/2)+1) for x in range(2,11)]
    str_f = " ".join(facts)
    for x in range(j):
        print "{0:b}".format(2**(n/2-1)+1+2*x)*2, str_f
