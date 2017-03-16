#include "svm.h"

int main(int argc, char *argv[]) {
	svm_options *option = new svm_options();	
	SMO *smo = new SMO(option);
	
	smo->train();
	smo->test();
}