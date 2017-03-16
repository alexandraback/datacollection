import sys
sys.stdin,sys.stdout= map(open, '1s_in.txt 1s_out.txt'.split(), 'r w'.split())
map_dict=dict()
def build_dictionary(s1,s2):
    if(len(s1)!=len(s2)):
        raise "the lengths of the strings should be the same"
    for c1,c2 in zip(s1,s2):
        if(c1.isspace()):continue
        map_dict[c1]=c2
def decrypt(s1):
    return reduce(lambda string, item: string + item, [map_dict[c] for c in s1], "")
build_dictionary('y','a')
build_dictionary('e','o')
build_dictionary('q','z')
build_dictionary('ejp mysljylc kd kxveddknmc re jsicpdrysi','our language is impossible to understand')
build_dictionary('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities')
build_dictionary('de kr kd eoya kw aej tysr re ujdr lkgc jv','so it is okay if you want to just give up')
for c in xrange(ord('a'),ord('z')+1):
    if(chr(c) not in map_dict):
        to_list=[]
        for c1 in map_dict:
            to_list.append(map_dict[c1])
        for c1 in xrange(ord('a'),ord('z')+1):
            if (chr(c1) not in to_list):
                map_dict[chr(c)]=chr(c1)
                break
map_dict[' ']=' '
number_of_lines=int(raw_input())
for (idx,c) in enumerate(xrange(number_of_lines)):
    print 'Case #'+str(idx+1)+": "+decrypt(raw_input())
sys.stdout.flush()
sys.stdout.close()
sys.stdin.close()
