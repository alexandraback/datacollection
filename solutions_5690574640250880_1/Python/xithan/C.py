#!/Library/Frameworks/Python.framework/Versions/3.3/bin/python3.3
# Codejam ID 2974486
# Run with parameter
# -p for preprocessing
# -s for small input
# -l for large input
# -m=<int> for multithreading


from GCJ import GCJ


def parse(infile):
    R, C, M = GCJ.readints(infile)
    return R, C, M
    
def solve(data):
    MINE = "*"
    CLICK = 'c'
    FREE = '.'
    r,c,m = data
    free = r*c - m
    swap = False
    print("%d x %d, %d" % (r,c,m))
    if m == 0:
        field = [ [ FREE for x in range(c) ] for y in range(r) ]
    elif free == 1:   # nur einer frei geht immer
        field = [ [ MINE for x in range(c) ] for y in range(r) ]
    elif r == 1:
        field = [ [ MINE for x in range(c) ] for y in range(r) ]
        free = c - m
        for i in range(free):
            field[0][i] = FREE
    elif c == 1:
        field = [ [ MINE for x in range(c) ] for y in range(r) ]
        free = r - m
        for i in range(free):
            field[i][0] = FREE
        
    elif (r == 2 or c == 2) and (m % 2 == 1):  # eine Seite 2 mit ungerader Minenanzahl > 1 geht nie
         return "\nImpossible"
    elif m == 1:
        field = [ [ FREE for x in range(c) ] for y in range(r) ]
        field[r-1][c-1] = MINE
    elif free == 7 or free == 5 or free == 3 or free == 2:
        return "\nImpossible"
    else:    
        if (free % c) % 2 == 0:
            line = c
            height = r
        elif (free % r) % 2 == 0:
            line = r
            height = c
            swap = True
        elif c < r:
            line = c
            height = r
        else:
            line = r
            height = c
            swap = True
            
        field = [ [ MINE for x in range(line) ] for y in range(height) ]    
        rest = free
        y = 0
        if height >= 2:
            for x in range(line):
                field[y][x] = FREE
                field[y+1][x] = FREE
                rest -= 2
                if rest == 3:
                    field[y+2][2] = FREE
                    field[y+2][1] = FREE
                    field[y+2][0] = FREE
                    rest = 0
                    break
                if rest == 0: 
                    break
        
        y += 2
        while y < height and rest > 0:
            for x in range(line):
                field[y][x] = FREE
                rest -= 1
                if rest == 0:
                    break
            y += 1

        if free % line == 1: # single ending
            y -= 1
            field[y-1][line-1] = MINE
            field[y][1] = FREE
            if y == 2:
                field[y-2][line-1] = MINE
                field[y][2] = FREE
            
    field[0][0] = CLICK
    

    if swap:
        res = [ [field[x][y] for x in range(c)] for y in range(r)]
    else:
        res = field
    return '\n'+ '\n'.join(map(lambda x: ''.join(x),res))
   


if __name__ == "__main__":
    GCJ('C', solve, parse, None).run()

