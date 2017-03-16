import sys


T = int(sys.stdin.readline().strip())
for i in xrange(T):
    R, C, W = (int(x) for x in sys.stdin.readline().strip().split())
    if W == C:
        guesses_to_sink_column = W
    elif C % W == 0:
        guesses_to_sink_column = C/W - 1  + W
    else:
        guesses_to_sink_column = C/W + W
    total_guesses = guesses_to_sink_column * R
    print 'Case #{}: {}'.format(i+1, total_guesses)
            
