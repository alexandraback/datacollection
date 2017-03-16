import re
import string
import sys

example_input = '''
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
zq
'''

example_output = '''
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
qz
'''



# build mapping using examples
example_input = re.sub(r'\s+', '', example_input)
example_output = re.sub(r'\s+', '', example_output)
mapping = {' ':' '}
for (k,v) in zip(example_input, example_output):
  mapping[k] = v

# warn about missing characters
for k in string.ascii_lowercase:
  if k not in mapping:
    print "How do you read '{}'?".format(k)

with open(sys.argv[2], 'w') as f_out:
  with open(sys.argv[1]) as f_in:
    for (i, line) in enumerate(f_in):
      line = line.strip()
      if re.match(r'\d+', line):
        continue
      translated = [mapping.get(k, '?') for k in line]
      translated = ''.join(translated)
      
      print 80*'-'
      print line
      print translated

      assert not '?' in translated

      f_out.write('Case #{}: {}\n'.format(i, translated))
