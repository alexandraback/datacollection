import sys

facts = {0: 1}
def fact(x):
    if x not in facts:
        facts[x] = x * fact(x-1)
    return facts[x]

def solve(N, X, Y):

    if (X + Y) % 2 != 0:
        return 0.0

    shell = (abs(X) + abs(Y)) // 2 + 1
    num_in_shell = 2*shell*shell - shell

    if N >= num_in_shell:
        # This shell is complete.
        return 1.0

    if X == 0:
        # Top point is the last to go in so isn't present if the shell isn't
        # full.
        return 0.0

    last_shell = shell - 1
    num_in_last_shell = 2*last_shell*last_shell - last_shell

    if N <= num_in_last_shell:
        # There aren't any in this shell yet.
        return 0.0

    candidates = N - num_in_last_shell

    needed_on_side = Y + 1

    if candidates < needed_on_side:
        # Don't have enough to reach that high
        return 0.0

    side_length = 2*(shell - 1)

    if candidates >= side_length + needed_on_side:
        # Certain
        return 1.0

    return (1 - (float(fact(candidates)) / 2**candidates) * 
                sum(1.0/(fact(i)*fact(candidates-i)) 
                   for i in xrange(needed_on_side)))

if __name__ == "__main__":

    infile = sys.stdin
    outfile = sys.stdout

    T = int(infile.readline())

    for test in xrange(1, T+1):
        N, X, Y = [int(num) for num in infile.readline().split()]

        prob = solve(N, X, Y)

        outfile.write("Case #{}: {}\n".format(test, prob))
