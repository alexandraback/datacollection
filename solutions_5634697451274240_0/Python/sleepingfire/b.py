import sys, os

def main(s):
    diff = 0
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            diff += 1
    if s[-1] == '-':
        diff += 1
    return diff

if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        s = in_file.readline().rstrip()
        res = main(s)
        print("Case #{}: {}".format(case_idx + 1, res))
