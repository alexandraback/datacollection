# Google Code jam d 

# Observations: 
# We cannot fill the area (Richard wins) if: 
# 1) N is not a multiple of R * C 
# 2) We can make an n-omino with a hole (N >= 7)
# 3) We can make an n-omino that doesn't fit into the grid. 

# Therefore, I can brute force through N = 1 through 6 because I played way too much Blokus
#   N  |  Non-trivial excluded values (trivial is if it violates one of the conditions above)
# =========================
#   1  |  Anything works
#   2  |  Anything works 
#   3  |  1x3 doesn't work. 
#   4  |  2x4 doesn't work because of the T piece. 
#   5  |  3x5 doesn't work because of the zig-zag piece
#   6  |  3x6 doesn't work because of the T piece. 

filename = 'D-small-attempt0.in'

def can_tile(r, c, n):
    """ r is the number of rows, c is the number of columns, n is the number of squares in a n-omino""" 
    
    if (r * c) % n != 0:
        return False
    if n >= 7:
        return False 
    
    min_sizes = ((0, 0), (1,1), (2,1), (3,2), (4,3), (5,4), (6,4)) # this is the minimum size (inclusive) to return true.
    if max(r,c) < min_sizes[n][0] or min(r, c) < min_sizes[n][1]:
        return False 
    return True
    
    
if __name__ == '__main__':
    filein = open(filename)
    fileout = open(filename.split('.')[0] + '.out', 'w')
    
    t = int(filein.readline()) # num test cases
    for i in range(t):
        n, r, c = (int(i) for i in filein.readline().split())

        if can_tile(r, c, n):
            fileout.write("Case #{}: GABRIEL\n".format(i + 1))
        else:
            fileout.write("Case #{}: RICHARD\n".format(i + 1))
    
    fileout.close()
    print("done")
