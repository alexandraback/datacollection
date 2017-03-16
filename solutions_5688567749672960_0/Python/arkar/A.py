import Queue

def attempt(N):
    pass


NUM_STEPS = 1500000


if __name__ == "__main__":


#    print "FFSDF"
    datastore = Queue.Queue()
    datastore.put((1, 1))
    covered = set()
    dist = {}
    for i in xrange(NUM_STEPS):
        x, d = datastore.get()
        if x in dist:
            continue
        dist[x] = d
#        print x, d
        if (x + 1) not in covered:
            datastore.put((x + 1, d + 1))
            covered.add(x+1)
        a = str(x)
        newElem = int(a[::-1])
        if newElem not in covered:
            datastore.put((newElem, d + 1))
            covered.add(newElem)

    print len(covered)
    print len([x for x in dist if x <= 1000000])


    T = int(raw_input())
    for i in xrange(T):
        n = int(raw_input())
        print "Case #%s: %s" % (i +1, dist[n])


# If the hiker closer to us will get to the end before being lapped, we just follow him...if he is going to get lapped, the
# other guy must be faster, so we pass him. Easy to implement.


# Think until 12.40 harder ones, then write pseudo-code and implement

# THeory about B-large: 0 until ceil(c/2)* ceil(r/2)  + floor(c/2)* floor(r/2) until there 0

# For B: Try to brute-force and then extract pattern, after B small


# Pseudocode C
#  Get number of people
#   If just one person, return 0
#   If two people, get starting positions
#       See how long do they take to go back to the origin from their current position
#       If that + one lap is less <= than what the other guy takes to go back to the origin, we are fucked -> answer is one


# At 1.45,switch

# ~~~~~~~

# For A large:

#-> 19 -> 91-> 92 -> 29

#So...cannot ignore....

#Well, just do bfs

# Then, look for pattern ... do search and bound?

#-> 30 -> 93 -> 109 -> 901 -> 9019 -> 9109 -> 10001

# ->


# A pseudo code

# Get number and position:
#  -> If position in table, return
#  -> Put position in table
#  -> If already examined, return
#  -> Add to queue, with position
#   -> Get reverse
#   -> Get next
#   -> If added, ignore, otherwise add to queue
#   -> Mark as added
#   -> When all numbers < 1000000 added, return

# Too long...

# Yeah, don't do this. Needs better solution to avoid loops

# B Pseudo-code
# keep a map
# Receive cell index
# Compute row and column
# Try in next cell, putting someone here and not, unless num_people = 0, then just no

# If we are in cell r*c, and more people here than 0, skip
# Otherwise, evaluate

# Eval function:
# Iterate over all rows:
#   Iterate over all columns except last. If in here and next, add wall
# Same for columns