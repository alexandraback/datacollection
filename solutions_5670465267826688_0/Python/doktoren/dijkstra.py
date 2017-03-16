import sys

P1 = 1 << 0
M1 = 1 << 1
Pi = 1 << 2
Mi = 1 << 3
Pj = 1 << 4
Mj = 1 << 5
Pk = 1 << 6
Mk = 1 << 7


def mult_i(v):
    return ((Pi if (v & P1) else 0) |
            (Mi if (v & M1) else 0) |
            (M1 if (v & Pi) else 0) |
            (P1 if (v & Mi) else 0) |
            (Mk if (v & Pj) else 0) |
            (Pk if (v & Mj) else 0) |
            (Pj if (v & Pk) else 0) |
            (Mj if (v & Mk) else 0))

def mult_j(v):
    return ((Pj if (v & P1) else 0) |
            (Mj if (v & M1) else 0) |
            (Pk if (v & Pi) else 0) |
            (Mk if (v & Mi) else 0) |
            (M1 if (v & Pj) else 0) |
            (P1 if (v & Mj) else 0) |
            (Mi if (v & Pk) else 0) |
            (Pi if (v & Mk) else 0))

def mult_k(v):
    return ((Pk if (v & P1) else 0) |
            (Mk if (v & M1) else 0) |
            (Mj if (v & Pi) else 0) |
            (Pj if (v & Mi) else 0) |
            (Pi if (v & Pj) else 0) |
            (Mi if (v & Mj) else 0) |
            (M1 if (v & Pk) else 0) |
            (P1 if (v & Mk) else 0))

transition = {(v, c):func(v)
              for (c, func) in (('i', mult_i), ('j', mult_j), ('k', mult_k))
              for v in range(256)}

p = lambda v: "".join("1" if ((1<<i) & v) else "0" for i in range(8))

def solve(s, x):
    v_i = P1
    v_j = 0
    v_k = 0
    previous_states = list()
    for i in range(1, x+1):
        for c in s:
            v_i = transition[(v_i, c)]
            v_j = transition[(v_j, c)] | (P1 if (v_i & Pi) else 0)
            v_k = transition[(v_k, c)] | (P1 if (v_j & Pj) else 0)
            # print "{} {}: {} {} {}".format(i, c, p(v_i), p(v_j), p(v_k))
        state = v_i | (v_j << 8) | (v_k << 16)
        for j in range(i-1, 0, -1):
            # print "{} {} {}".format(i, j, previous_states)
            if state == previous_states[j-1]:
                if (x-i) % (i-j) == 0:
                    return bool(v_k & Pk)
                break
        previous_states.append(state)
    return bool(v_k & Pk)

with open(sys.argv[1], 'r') as f:
    t = int(f.readline().strip())
    for n in range(1, t+1):
        _, x = (int(s) for s in f.readline().strip().split(" "))
        s = f.readline().strip()
        print "Case #{}: {}".format(n, "YES" if solve(s, x) else "NO")
