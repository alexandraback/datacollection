training_text="ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jvzq"
training_conversion="our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give upqz"

map = {}

for i in xrange(len(training_text)):
    char_original = training_text[i]
    char_transform = training_conversion[i]
    map[char_original] = char_transform
    
        
in_file = open("A-small-attempt0.in", "r")

# Read length.
line = in_file.readline()
input_length = int(line)

# Read lines.
if input_length > 0:
    for on_line in xrange(input_length):
        line = in_file.readline()
        if line[-1] == '\n':
            line = line[:-1]    # Strip newline.
        newline = ""
        for i in xrange(len(line)):
            newline += map[line[i]]
        print "Case #" + str(on_line + 1) + ": " + newline