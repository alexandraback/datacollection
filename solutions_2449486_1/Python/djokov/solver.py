def clean(ls):
    new_ls = []
    for item in ls:
        new_ls.append(int(item))
    return new_ls

def solve(sample):
    rows = len(sample)
    cols = len(sample[0])
    row_mins = [100] * rows
    col_mins = [100] * cols
    
    for i in range(rows):
        row_mins[i] = max(sample[i])
    
    for j in range(cols):
        values = []
        for i in range(rows):
            values.append(sample[i][j])
        col_mins[j] = max(values)
    

    for i in range(rows):
        for j in range(cols):
            if sample[i][j] != row_mins[i] and sample[i][j] != col_mins[j]:
                return "NO"
    
    return "YES"
file = open('B-large.in')
lines = file.readlines()
sample_count = int(lines[0].strip())
    
samples = []

# read in file
current = 1
for k in range(sample_count):
    rows = int(lines[current].strip().split(" ")[0])
    values = []
    for i in range(1,rows+1):
        values.append(clean(lines[current+i].strip().split(" ")))
    
    samples.append(values)
    current = current + rows + 1

out = open("results.out", "w")

# solve
for k in range(sample_count):
    print >> out, "Case #"+str(k+1)+":", solve(samples[k])



