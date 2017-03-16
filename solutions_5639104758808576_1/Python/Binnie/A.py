import sys


def get_audience_required(audience):
    num_so_far = 0
    extras_required = 0
    for ii in range(len(audience)):
        extras_required = max(extras_required, ii - num_so_far)
        num_so_far += int(audience[ii])

    return extras_required


f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    max_S, audience = f.readline().split()

    print "Case #%d: " % (test + 1), get_audience_required(audience)