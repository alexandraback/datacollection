import sys
import fileinput

fin = fileinput.input()
fout = sys.stdout

def solve(lawn):
    row_max = list(map(max, lawn))
    lawn_t = list(map(list, zip(*lawn)))
    col_max = list(map(max, lawn_t))
    
    for r, row in enumerate(lawn):
        for c, val in enumerate(row):
            if col_max[c] > val and row_max[r] > val:
                return False 
            
    return True

def main():
    T = int(fin.readline())
    
    for case_idx in xrange(T):
        N, M = tuple(map(int, fin.readline().split()))
        
        lawn = []
        for n in xrange(N):
            lawn.append(list(map(int, fin.readline().split())))
        
        result = "YES" if solve(lawn) else "NO"
        fout.write("Case #{0}: {1}\n".format(case_idx + 1, result))

if __name__ == "__main__":
    main()
