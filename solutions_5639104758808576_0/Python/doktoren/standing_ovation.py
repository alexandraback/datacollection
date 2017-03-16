import sys

def solve(s):
    count = 0
    friends = 0
    for shyness, ch in enumerate(s):
        if ch != '0' and shyness - count > friends:
            friends = shyness - count
        count += int(ch)
    return friends
    
with open(sys.argv[1], 'r') as f:
    t = int(f.readline().strip())
    for n in range(1, t+1):
        _, s = f.readline().strip().split(" ")
        print "Case #{}: {}".format(n, solve(s))
