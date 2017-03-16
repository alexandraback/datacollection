if __name__ == '__main__':
    def get_time(c, f, x, rate, start=0):
        stack = [(rate, start)]
        while len(stack):
            nr, ns = stack.pop()

            p1 = ns + x / nr
            p2 = ns + c / nr + x / (nr + f)

            if p1 <= p2:
                return p1
            stack.append((nr + f, ns + c / nr))

    for casenum in range(input()):
        c, f, x = [float(i) for i in raw_input().split()]
        print 'Case #%d: %.8f' % (casenum + 1, get_time(c, f, x, 2.0))
