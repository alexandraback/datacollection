t=input()
for tc in xrange(0,t):
    template="Case #"+str(tc+1)+":"
    s=raw_input()
    zero=s.count('Z')
    one=s.count('O')-s.count('Z')-s.count('U')-s.count('W')
    two=s.count('W')
    three=s.count('H')-s.count('G')
    four=s.count('U')
    five=s.count('F')-s.count('U')
    six=s.count('X')
    seven=s.count('V')-five
    eight=s.count('G')
    nine=s.count('I')-(five+six+eight)
    ans='0'*zero+'1'*one+'2'*two+'3'*three+'4'*four+'5'*five+'6'*six+'7'*seven
    ans+=('8'*eight+'9'*nine)
    print template,ans
    
