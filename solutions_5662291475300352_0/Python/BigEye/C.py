#!/usr/bin/python

def get_values(ds, ts, df, tf):
    B = (360 - ds) / (360 / ts)
    C = (360 - (df - ds)) / ( (360 / tf) - (360 / ts) )
    A = 360 / ( (360 / tf) - (360 / ts) )
    return (A, B, C)

def num_encounters(ps):
    if (len(ps) <= 1):
        return 0
    ds = Fraction(ps[0][0])
    ts = Fraction(ps[0][1])
    df = Fraction(ps[1][0])
    tf = Fraction(ps[1][1])
    if (ts == tf):
        return 0
    if (ts < tf):
        ds, df = df, ds;
        ts, tf = tf, ts;
    A, B, C = get_values(ds, ts, df, tf)

    if (df == ds):
        return 0 if B < A else 1
    if (df > ds):
        return 0 if (B - C < A) else 1

    enc = (ds - df) / ( (360 / tf) - (360 / ts) )
    enc *= (360 / tf)
    enc += df

    # print float(enc)
    if (enc >= 360):
        return 0
    A, B, C = get_values(enc, ts, enc, tf)
    return 0 if B < A else 1


from fractions import Fraction
tn = int(raw_input())
for ti in range(1, tn + 1):
    n = int(raw_input())
    ps = []
    for _ in range(n):
        d, h, m = map(int, raw_input().split(' '))
        for mi in range(m, m+h):
            ps.append((d, mi))

    print "Case #%d: %d" % (ti, num_encounters(ps))
