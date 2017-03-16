def stripped_lines(fh):
    return (line.rstrip('\n') for line in fh)

def ints(s):
   return [int(num) for num in s.split()]