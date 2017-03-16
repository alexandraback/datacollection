fi = open('small.in', 'r')
fi = open('small2.in', 'r')
fi = open('A-large.in', 'r')
# fi = open('A-small-attempt0.in', 'r')
fo = open('aresult.out', 'w')

T = int(fi.readline())

CANTSLEEP = 'INSOMNIA'
def solve_special_case(N):
    if N == 0:
        return CANTSLEEP
    elif N == 1:
        return 10
    elif N == 2:
        return 90

def solve(N):
    found_digits = set()
    found_flag = False
    run_flag = True
    mul_factor = 0
    last_number = 0

    while(True):
        mul_factor += 1
        last_number += N
        # fo.write('%i\t' % last_number)

        if mul_factor == 100000: # stop while loop
            print "TOO MUCH TO HANDLE"
            break

        digits = _get_digit(last_number)
        for d in digits:
            found_digits.add(d)

        if len(found_digits) == 10:
            found_flag = True
            break

    if found_flag:
        return last_number
    else:
        return CANTSLEEP


def _get_digit(number):
    digits = [int(n) for n in str(number)]
    return digits

for t in range(1, T+1):
    N = int(fi.readline())

    if N in [0, 1, 2]:
        output_val = solve_special_case(N)
    else:
        output_val = solve(N)

    # print output_val
    # output_val = 0
    # print 'Case #%i: %s\n' % (t, output_val)
    fo.write('Case #%i: %s\n' % (t, output_val))