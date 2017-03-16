#######################
##     Google Jam
##    Python template
##
##       by fxxf
##############


def timeIt(f):
    from time import clock

    def wrap(*args, **kwargs):
        t = clock()
        ret = f(*args, **kwargs)
        print f.__name__, clock()-t
        return ret
    return wrap


@timeIt
def main():
    from argparse import ArgumentParser

    parser = ArgumentParser()
    parser.add_argument("input", help="The input file")
    args = parser.parse_args()

    vowels = frozenset(['a','e','i','o','u'])

    def check(string):

        last = 0
        m = 0
        for c in string:
            if c not in vowels:
                last += 1
                m = max(m, last)
            else:
                last = 0

        return m

    with open(args.input, 'r') as input, open("./output.out", "w") as output:

        ## _----------____ INSERT CODE BELOW _____------------_
        CASES = int(input.readline())

        for c in xrange(1, CASES + 1):

            name, N = input.readline().split()
            N = int(N)

            n_value = 0 
            
            for i in xrange(0, len(name)-N+1):

                for j in xrange(i+N, len(name)+1):

                    if check(name[i:j]) >= N:
                        n_value += 1 


            output.write("Case #%(c)i: %(n_value)d\n" % locals())
            pass

        ## _----------____ INSERT CODE ABOVE _____------------_
        pass
    return


if __name__ == '__main__':
    main()
    pass
