from base import cases

def solve(kcs):
    k, c, s = tuple(int(x) for x in kcs.split(" "))
    if k > s*c: return "IMPOSSIBLE"
    t=0
    nums = []
    while t < k:
        num = 1 + sum(min(t+x, k-1)*k**(c-1-x) for x in range(c))
        nums.append(str(num))
        t += c
    return " ".join(nums)

if __name__ == "__main__":
    cases(solve)
