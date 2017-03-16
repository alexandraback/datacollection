__author__ = 'j0hnny'

if __name__ == '__main__':
    times = []

    with open('B-small-attempt1.in', 'r') as input:
        cases = int(input.readline())
        for c in range(cases):
            (f_cost, f_inc, total) = [float(v) for v in input.readline().split()]

            curr_inc = 2.0
            t = 0.0
            while (total/curr_inc) > (f_cost/curr_inc + total/(curr_inc + f_inc)):
                t += f_cost/curr_inc
                curr_inc += f_inc
            t += total/curr_inc

            times.append(t)

    with open('output', 'w') as output:
        for c in range(cases):
            s = 'Case #%d: %.7f\n' % (c+1, times[c])
            print s
            output.write(s)