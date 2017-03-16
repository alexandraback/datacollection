import sys

def create_field(f, height, width):
    field = []
    for i in range(height):
        row = [int(x) for x in f.readline().split()]
        field.append(row)
    return field

def remove_row(field, row):
    del field[row]
    
def remove_col(field, col):
    for row in field:
        del row[col]

def find_min_height(field):
    return min([min(row) for row in field])

def num_in(num, field):
    for row in field:
        if num in row:
            return True
    return False
    
def remove_min(field, min_h):
    rows_to_delete = []
    height = len(field)
    for i in range(height):
        row = field[i]
        all_row = True
        for cell in row:
            if cell != min_h:
                all_row = False
                break
        if all_row:
            rows_to_delete.append(i)
    rows_to_delete.sort()
    rows_to_delete.reverse()
    for i in rows_to_delete:
        remove_row(field, i)
        
    if is_field_empty(field):
        return
    
    height = len(field)
    width = len(field[0])
    cols_to_delete = []
    for i in range(width):
        all_col = True
        for j in range(height):
            if field[j][i] != min_h:
                all_col = False
                break
        if all_col:
            cols_to_delete.append(i)
    cols_to_delete.sort()
    cols_to_delete.reverse()
    for j in cols_to_delete:
        remove_col(field, j)
        
def is_field_empty(field):
    for row in field:
        if len(row) > 0:
            return False
    return True
    
def test(field):
    old_min_h = 0
    while not is_field_empty(field):        
        min_h = find_min_height(field)
        if min_h == old_min_h:
            return False
        remove_min(field, min_h)
        old_min_h = min_h
    return True
 
if __name__=="__main__":
    filename = sys.argv[1]
    f = open(filename, 'r')
    numtests = int(f.readline()) 
    for i in range(1, numtests+1):
        l = f.readline().split()
        height = int(l[0])
        width = int(l[1])
        field = create_field(f,height,width)
        if test(field):
            print "Case #" + str(i)+": YES"
        else:        
            print "Case #" + str(i)+": NO"
        
test_field = [[2,1,2],[1,1,1],[2,1,2]]