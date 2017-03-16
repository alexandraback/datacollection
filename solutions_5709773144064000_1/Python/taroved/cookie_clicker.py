import sys

input_file = sys.argv[1]
output_file = "%s.out" % input_file.split('.')[0]
print "INPUT FILE: %s" % input_file
print "OUTPUT FILE: %s" % output_file

def read_row(file):
    row = file.readline().split()
    return float(row[0]), float(row[1]), float(row[2])

def calc_time(speed, target):
    return target / speed
    
results = list()
history_times = list() 
with open(input_file) as f:
    row_cout = int(f.readline())
    for i in xrange(0,row_cout):
        C, F, X = read_row(f)
        speed = 2
        time = 0
        farm_count = 0
        cur_time = time + X/speed
        while True:#while True:
            time += C / speed
            speed += F
            next_time = time + X/speed
            if (cur_time < next_time):
                break;
            else:
                cur_time = next_time
        results.append(cur_time)

with open(output_file, 'w') as f:
    i = 1
    for result in results:
        f.write("Case #%s: %s\n" % (i, result))
        i += 1