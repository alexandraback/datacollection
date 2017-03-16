#!python
def solve(row, col, width):
    rest = 0 if col % width == 0 else 1
    return (col/width - 1) + width + rest

def main():
    n = int(raw_input())
    for c in range(1, n + 1):
        R, C, W = map(int, raw_input().split())
        score = solve(R,C,W)
        print 'Case #%d: %d' % (c, score)
    
if __name__ == "__main__":
  main()
    