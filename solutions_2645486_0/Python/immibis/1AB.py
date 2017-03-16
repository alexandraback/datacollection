infile = "1ABsmall.txt"

def solve(energy, time):
    # Either spend as much or as little energy as possible.
    # Return tuple (best-solution, best-gain)

    if time >= len(values):
        return ([], 0)

    if energy > E:
        print("shouldn't happen 2")
        energy = E

    maxSpend = energy
    minSpend = 0 if energy + R <= E else (energy + R) - E
    
    bestsol = []
    besttotal = 0
    bestspend = 0

    for spend in range(minSpend, maxSpend+1):
        if energy < spend:
            print("shouldn't happen")
            continue
        gain = values[time] * spend
        nsol, ngain = solve(energy - spend + R, time + 1)
        total = gain + ngain

        if total >= besttotal:
            besttotal = total
            bestsol = [spend] + nsol
            bestspend = spend

    #if bestspend != minSpend and bestspend != maxSpend:
        #print("? best is %i, min/max %i/%i" % (bestspend, minSpend, maxSpend))

    return (bestsol, besttotal)

with open(infile, "r") as f:
    with open("output.txt", "w") as o:
        nc = int(f.readline())
        for c in range(nc):
            E, R, N = [int(x) for x in f.readline().split(" ")]
            R = min(R, E)
            values = [int(x) for x in f.readline().split(" ")]
            sol, gain = solve(E, 0)
            print(str(c+1)+": "+repr(sol))
            o.write("Case #%i: %i\n" % (c+1, gain))
        














