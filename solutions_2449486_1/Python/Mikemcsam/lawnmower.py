def lawnmower(lawn, height, width):
    max_rows = [max(lawn[i][j] for j in range(width)) for i in range(height)]
    max_cols = [max(lawn[j][i] for j in range(height)) for i in range(width)]
    for i in range(height):
        for j in range(width):
            if lawn[i][j] < max_rows[i] and lawn[i][j] < max_cols[j]:
                return "NO"
    return "YES"

import sys
if __name__ == "__main__":
    f = sys.stdin
    tests = int(next(f).strip())
    for i in range(tests):
        height,width = [int(value) for value in next(f).split()]
        lawn = []
        for j in range(height):
            lawn.append([int(value) for value in next(f).split()])
        print("Case #"+str((i+1))+ ": "+lawnmower(lawn,height,width))
            
    
   