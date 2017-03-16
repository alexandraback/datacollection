def pancake(stack):
    return reduce(lambda a, n: (a[0] + (a[1] != n), n),
                  reversed(stack), (0, '+'))[0]

if __name__ == '__main__':
    cases = int(raw_input())
    for i in range(cases):
        print("Case #%s: %s" % (i+1, pancake(raw_input())))
