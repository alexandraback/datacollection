def reader(inFile):
    (num, den) = [int(z) for z in inFile.readline().split("/")]
    return (num, den)

from fractions import gcd

def solver((num, den)):
    g = gcd(num, den)
    num /= g
    den /= g
    den2 = den
    while (den2 > 0):
        if den2 == 1:
            break
        if den2 & 1:
            return "impossible"
        den2 /= 2
    # if 1/2 <= num / den < 1,
    ans = 1
    while den > (num << ans):
        ans += 1
    return ans

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/luke/gcj/2014/1c/a/", "a").run()
