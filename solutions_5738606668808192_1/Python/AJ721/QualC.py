def check_coinjam(nstr, factors):
  for base in xrange(2,11):
    n = int(nstr,base)
    if n % factors[base-2] != 0:
      return False
  return True
  
def double(str):
  str2 = ""
  for c in str:
    str2+=c+c
  return str2
  
def do_case(N,J):
  magic = [3,2,5,3,7,2,3,5,11]
  magics = [str(s) for s in magic]
  out="Case #1:\n"
  for i in xrange(J):
    bin = "1"+("{0:b}".format(i).zfill(N/2-2)) +"1"
    db = double(bin)
    if check_coinjam(db, magic):
      out += db+" "+(" ".join(magics)) + "\n"
    else:
      raise ValueError("Math broke")
  return out
  
#print(check_coinjam("1010100000010101",[3,7,3,3,31,3,3,7,3]))
#print(check_coinjam( "1100000110000011",[3,2,5,3,7,2,3,5,11]))


open("C-small.out","w").write(do_case(16,50))
open("C-large.out","w").write(do_case(32,500))