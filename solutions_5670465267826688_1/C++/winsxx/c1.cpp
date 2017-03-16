#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
	bool sign;
	char dim;
} quat;

quat mulQuaternion(quat a, quat b){
	quat ans;
	ans.sign = a.sign ^ b.sign;
	
	if(a.dim == '1'){
		ans.dim = b.dim;
	} else if (b.dim == '1'){
		ans.dim = a.dim;
	} else if (a.dim == b.dim){
		ans.dim = '1';
		ans.sign = !ans.sign;
	} else if (a.dim == 'i'){
		if (b.dim == 'j'){
			ans.dim = 'k';
		} else if (b.dim == 'k'){
			ans.dim = 'j';
			ans.sign = ! ans.sign;
		}
	} else if (a.dim == 'j'){
		if (b.dim == 'i'){
			ans.dim = 'k';
			ans.sign = !ans.sign;
		} else if (b.dim == 'k'){
			ans.dim = 'i';
		}
	} else if (a.dim == 'k'){
		if (b.dim == 'i'){
			ans.dim = 'j';
		} else if (b.dim == 'j'){
			ans.dim = 'i';
			ans.sign = ! ans.sign;
		}
	}
	
	return ans;
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		int L;
		long long X;
		int rX;
		scanf("%d %lld", &L, &X);
		
		if (X>8) X = X%4+4;
		rX = (int) X;
		
		char misspell[L+5];
		scanf("%s", misspell);
		
		quat quaternion[L+5];
		for(int i=0; i<L; i++){
			quat temp;
			temp.sign = false;
			temp.dim = misspell[i];
			quaternion[i] = temp;
		}
		
		quat sum;
		sum.sign = false;
		sum.dim = '1';
		int state = 1;
		for(int i=0; i<L*rX; i++){
			sum = mulQuaternion(sum, quaternion[i%L]);
			if(state == 1 && sum.dim == 'i'){
				state++;
				sum.dim='1';
			}else if(state == 2 && sum.dim == 'j'){
				state++;
				sum.dim='1';
			}else if(state == 3 && sum.dim == 'k'){
				state++;
				sum.dim='1';
			}
		}
		
		printf("Case #%d: ", t);
		if (sum.sign == false && sum.dim =='1' && state==4) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}