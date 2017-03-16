def min_needed(string):
    standing = 0
    diff = 0
    
    for i in range(len(string)):
        peeps = int(string[i])
        
        if standing >= i:
            standing += peeps
        elif peeps > 0:
            diff += i - standing
            standing = i + peeps
    return diff



file_name = 'A-large.in'
out = open('large_standing_ovation.out', 'w')
with open(file_name) as f:
    T = int(next(f))
    count = 0
    
    for line in f:
        b = [str(i) for i in line.strip().split()]
        a = min_needed(b[1])
        out.write("Case #%d: %d\n" % (count + 1, a))
        count += 1

out.close()