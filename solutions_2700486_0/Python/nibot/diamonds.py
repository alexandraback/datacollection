#!/usr/bin/python

def combine_ensembles(a, b):
    for x in b:
        if x in a:
            a[x] += b[x]
        else:
            a[x] = b[x]
    return a

def occupied(conf, x, y):
    return (x,y) in conf

# An ensemble is a mapping from configurations to probabilities
def add_diamond(conf, x, y):
    conf = set(conf)
    #print "Adding a diamond to " + str(conf) + " at (%d, %d) " % (x,y)
    # Add a diamond at position x, y.  Return resulting ensemble

    # Fall until blocked directly below, or have hit the ground
    while (y>0):
        if occupied(conf, x-1, y-1) and occupied(conf, x+1, y-1):
            break # we're stuck
        elif occupied(conf, x-1, y-1) and not occupied(conf, x+1, y-1):
            # slide to the right
            x += 1
            y -= 1
        elif not occupied(conf, x-1, y-1) and occupied(conf, x+1, y-1):
            # slide to the left
            x -= 1
            y -= 1
        elif occupied(conf, x, y-2):  # Now we're free -- maybe -- to hop down two spaces
            # Here we have to do a non-deterministic branch.  We already know that both of
            # these spots are free - otherwise we would have had to slide.
            a = add_diamond(conf, x-1, y-1) 
            b = add_diamond(conf, x+1, y-1)
            for x in a: a[x] *= 0.5
            for x in b: b[x] *= 0.5
            return combine_ensembles(a, b)
        else:
            # we're free to fall directly downwards
            y -= 2
    # Now we're either stuck or in the ground.  This is a definite result.
    return { frozenset(set(conf) | set([(x,y)])) : 1 }
    
        
def calculate_probability(ensemble, x, y):
    # Find the probability that there's a diamond at (x,y) given
    # ensemble of configurations
    p = 0
    for conf in ensemble:
        if (x,y) in conf:
            p += ensemble[conf]
    return p

def simulate(X, Y, N):
    # The initial state definitely contains nothing:
    ensemble = { frozenset([]) : 1.0  } 
    # Now add diamonds one-by-one:
    for n in xrange(0, N):
        new_ensemble = dict()
        for conf in ensemble:
            e = add_diamond(conf, 0, 20)
            for c in e: e[c] *= ensemble[conf]   # multiply by the prior
            new_ensemble = combine_ensembles(new_ensemble, e)   # add to our collection

        ensemble = new_ensemble
        #print ensemble
        # If a block already is known to land at the chosen spot, we
        # can quit now:
        p = calculate_probability(ensemble, X, Y)
        if p > (1.0 - 1e-6):
            return p

    return p
        
        
        

numbers = map(int, raw_input().split())
T = numbers.pop(0)

for t in xrange(0, T):
    numbers = map(int, raw_input().split())
    N = numbers.pop(0)
    X = numbers.pop(0)
    Y = numbers.pop(0)

    result = simulate(X, Y, N)
    print "Case #%d: %f" % (t+1, result)
