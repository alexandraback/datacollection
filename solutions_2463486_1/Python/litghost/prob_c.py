import gmpy

def read_problem(f):
    itr = iter(f)
    T = int(itr.next())

    for _ in xrange(T):
        yield map(gmpy.mpz, itr.next().strip().split())

def ispall(v):
    sv = str(v)

    return sv == sv[-1::-1]

def create_fair_numbers(low, high):
    low_sq = gmpy.sqrt(low)-1
    high_sq = gmpy.sqrt(high)+1

    while low_sq**2 < low:
        low_sq += 1

    while high_sq**2 > high:
        high_sq -= 1

    for v in xrange(low_sq, high_sq+1):
        if not ispall(v):
            continue

        sqv = v**2
        if ispall(sqv):
            yield sqv

def count_fair(values, low, high):
    count = 0

    for v in values:
        if v < low:
            continue

        if v > high:
            break

        count += 1

    return count

def main():
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--create', nargs=2)
    parser.add_argument('--solve', nargs=2)

    args = parser.parse_args()

    if args.solve:
        (cheat_sheet, problem) = args.solve

        with open(cheat_sheet) as f:
            values = map(int, iter(f))

        with open(problem) as f:
            for case, (low, high) in enumerate(read_problem(f)):
                print 'Case #%d: %d' % (case+1, count_fair(values, low, high))

    elif args.create:
        (low, high) = map(eval, args.create)

        for v in create_fair_numbers(low, high):
            print v
    else:
        parser.error('Must pass --create or --solve')


def timeme():
    import datetime
    start = datetime.datetime.now()
    count_fair(1, 10**14)
    print (datetime.datetime.now() - start)*10000

if __name__ == '__main__':
    main()
