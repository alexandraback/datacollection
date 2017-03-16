import sys

# INPUT DATA AND NUMBER OF TEST CASES
infile = open(sys.argv[1],'r')
T = infile.readline()
T = T.rstrip()

# ITERATE OVER EACH CASE
for index in range(1,int(T)+1):
    S = infile.readline().rstrip();

    last_word = S[0]

    for i in range(1,len(S)):
        if ord(S[i]) >= ord(last_word[0]):
            last_word = S[i] + last_word
        else:
            last_word = last_word + S[i]
    # OUTPUT IN THE FORM
    print 'Case #' + str(index) + ': ' + last_word
