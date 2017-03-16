inputfile = file("A-large.in", "rb")
outputfile = file("output.out", "wb")
out_s = "Case #%d: %d"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

vowels = 'aeiou'
cons = 'bcdfghjklmnpqrstvwxyz'

T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    input_string, num = inputfile.readline().split()
    k = int(num)
    for con in cons:
        input_string = input_string.replace(con, 'c')
    for vowel in vowels:
        input_string = input_string.replace(vowel, 'e')
    
    s = input_string
    start_index = -1
    end_index = -1
    last_pair_of_indices = [-1,-1]
    
    subs_counter = 0
    reset = True
    for i in xrange(len(s)):
        #print start_index, end_index
        if s[i] == 'c':
            if reset:
                if end_index - start_index+1 >= k:
                    last_pair_of_indices = [start_index, end_index]
                start_index = i
                end_index = i
                reset = False
            else:
                end_index = i
            if end_index-start_index+1 == k: # >= already treated by earlier =
                # Calculate tail
                tail = len(s) - end_index
                subs_counter += tail
                # Calculate head
                if last_pair_of_indices[0] == -1:
                    head = start_index
                else:
                    head = start_index - last_pair_of_indices[0] - 1
                subs_counter += head*tail
                #print "here", tail, head, s, k, start_index, end_index, last_pair_of_indices
            while end_index - start_index + 1 > k:
                #print 'there'
                start_index += 1
                # Calculate tail
                tail = len(s) - end_index
                subs_counter += tail     
                
        elif s[i] == 'e':
            reset = True
    print >>outputfile, out_s % (ncase, subs_counter)